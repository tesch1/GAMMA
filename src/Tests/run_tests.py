#run_tests.py
from __future__ import division

import os
import glob
import sys
import subprocess
import scipy
import scipy.io as sio
import filecmp as fc
from optparse import OptionParser

# define comparison function to be used by run_tests.py
def cmp_nn(file1, file2):
    # Compare two files 
    # ignoring the newlines (lf vs cr-lf)

    f1 = open(file1)
    f2 = open(file2)

    L1 = f1.readline()
    L2 = f2.readline()

    result = True
    while L1 or L2:
        L1 = L1.rstrip("\r\n\f")
        L2 = L2.rstrip("\r\n\f")
        if L1 != L2:
            result = False
            if is_verbose:
                print file1 + ": '" + L1 + "'"
                print file2 + ": '" + L2 + "'"
            break
        L1 = f1.readline()
        L2 = f2.readline()   

    f1.close()
    f2.close()
    return result


# define matlab comparison function to be used by run_tests.py
def cmp_mat(file1, file2):
    # Compare two matlab files 
    # ignoring the newlines (lf vs cr-lf)    

    contents1 = sio.loadmat(file1)
    contents2 = sio.loadmat(file2)

    data1 = contents1[ contents1.keys()[0] ]
    data2 = contents2[ contents2.keys()[0] ]

    if scipy.rank(data1) != scipy.rank(data2):
        print "Data sets in the two files are not of the same rank"
        return False

    if data1.shape != data2.shape:
        print "Data sets in the two files do not have the same shape"
        return False

    #print "About to run compare_data()"
    return compare_data(data1, data2)


def compare_data(data_1, data_2):

    max_relative_diff =  0.00000000001 # 1 part in 10 to the 11th.
    dontcare_point = 0.000000001 # 1 part in 10 to the 9th.

    l = len(data_1.shape)

    if l==0:
        #print "l==0"
        return compare_numbers(data_1, data_2, max_relative_diff, dontcare_point)

    if l == 1:
        #print "l==1"
        return compare_lists(data_1, data_2, max_relative_diff, dontcare_point)        
    else:
        #print "l>1"
        i = 0
        for d1 in data_1:
            d2 = data_2[i]
            result = compare_data(d1, d2)
            i += 1
            if result == True:
                continue
            else:
                return False

    return True


def compare_lists(sources, targets, max_relative_difference, do_not_care_point):
    for source, target in zip(sources, targets):
        if compare_numbers(source, target, max_relative_difference, do_not_care_point) == True:
            continue
        else:
            print "source = " + str(source)
            print "target = " + str(target)
            return False

    #print "returning true"
    return True


def compare_numbers(test_value, expected_value, max_relative_difference, do_not_care_point):
   
    # Compares two numbers (usually floats) for fuzzy equality.

    difference = abs(test_value - expected_value)

    # See if the difference is out of tolerance, and also meaningful
    # i.e. near-zero values sometimes show up as noise, like 7.382239e-304)

    if (difference > ( abs(expected_value) * max_relative_difference )) or \
       (difference > do_not_care_point):
        return False
    else:
        return True


# parse the command line.
parser = OptionParser()
parser.add_option("-p", "--path", dest="path", action="store", default=".",
                  help="path to executable test progams", metavar="PATH")
parser.add_option("-v", "--verbose", dest="verbose", 
                    action="store_true", default=False,
                    help="print status messages to stdout")

(options, args) = parser.parse_args()


filelist = glob.glob('*.suite')
total_failures = 0
total_comparisons = 0
is_verbose = options.verbose

print ""

for filename in filelist:
    bad_thing_happened = False
    current_suite = ""
    f = open(filename)
    for line in f.readlines():
        substrings = line.split(':')
        # validate that this data line has a valid format.
        if len(substrings) == 0 or len(substrings) > 2:
            continue
        if len(substrings) == 1:
            s = substrings[0].lstrip()
            if s:  
                # if there is something on this line and no ":", we have a problem.
                s = s.rstrip()
                print "\nBad command '" + s + "' in file: " + filename
                bad_thing_happened = True
                break
            else:
                # If this is effectively a blank line, then ignore,
                # and move on the the next line.
                continue
        # FIXME: 
        # We should add a check to make sure
        # the file does not try to compare files before
        # running the command, etc.

        # now try to interpret what we have.
        s = substrings[0]
        if s == "suite":
            current_suite = substrings[1].strip()
            print "Running Suite: " + current_suite + "\n"
        if s == "command":
            command = ""
            command += options.path
            command += substrings[1].lstrip()
            print "running command: " + command
            retcode = subprocess.call(command, shell=True)
            if retcode < 0:
                s1 = "Attempt to call " + substrings[1] + " was terminated by signal " + str(retcode)
                print >> sys.stderr, s1
        if s == "compare":
            total_comparisons += 1
            st = substrings[1]
            st = st.lstrip()
            st = st.rstrip()

            filenames = st.split(",")
            if len(filenames) < 2:
                print "Error while attempting to compare files"
                print "Filecount was too small"
                total_failures += 1
                continue

            file1 = filenames[0]
            file2 = filenames[1].lstrip()
            if is_verbose == True:
                print "Comparing: " + file1 + " " + file2

            filebad = False
            fileout = ""
            if os.path.exists(file1) == False:
                fileout = file1
                filebad = True
            elif os.path.exists(file2) == False:
                fileout = file2
                filebad = True
            if filebad:
                sys.stdout.write(" *** TEST FAILED ***\n")
                print ""
                print "Warning: Could not find file, " + fileout + " required for comparison"
                print ""
                total_failures += 1
                continue

            if file1.endswith(".mat"):
                if file2.endswith(".mat"):
                    result = cmp_mat(file1, file2)
                else:
                    print ""
                    print "Both files need to be of type matlab (i.e. 'xxx.mat')."
                    print ""
                    result = False
            else:
                result = cmp_nn(file1, file2)

            if result == False:
                if is_verbose == True:
                    print "*** TEST FAILED ***"
                    print ""
                total_failures += 1
                continue

    f.close()

    if bad_thing_happened == True:
        print ""
        print "*** Error while Running the \'" + current_suite + "\' Suite, Tests not complete!"

print "\nSummary:"
print "\tRan a total of " + str(total_comparisons) + " comparisons"
print "\tThere was " + str(total_failures) + " failure(s)"
print ""

