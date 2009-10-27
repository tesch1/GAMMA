#run_tests.py
from __future__ import division

import os
import glob
import sys
import subprocess
import filecmp as fc
from optparse import OptionParser

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
            command += options.path + "/"
            command += substrings[1].lstrip()
            retcode = subprocess.call(command, shell = True)
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
                sys.stdout.write("Comparing: " + file1 + " " + file2)

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

            result = fc.cmp(file1, file2)
            if result == False:	 
                if is_verbose == True:
                    sys.stdout.write(" *** TEST FAILED ***\n")
                total_failures += 1
                continue
            else:
                if is_verbose == True:
                    sys.stdout.write("\n")

    f.close()

    if bad_thing_happened == True:
        print ""
        print "*** Error while Running the \'" + current_suite + "\' Suite, Tests not complete!"

print "\nSummary:"
print "\tRan a total of " + str(total_comparisons) + " comparisons"
print "\tThere was " + str(total_failures) + " failure(s)"
print ""
