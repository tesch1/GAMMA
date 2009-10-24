#run_tests.py

import os as os
import glob as glob
import filecmp as fc
import sys as sys

filelist = glob.glob('*.suite')

failures = 0
total_comparisons = 0
bad_thing_happened = False

# FIXME
# use getopt or opionparse to get command line arguments
# like -v --verbose.
is_verbose = True

print("")

for filename in filelist:
	f = open(filename)
	linelist = f.readlines()
	current_suite = ""
	for line in linelist:
		substrings = line.split(':')		
		# validate that this data line has a valid format.
		if len(substrings) == 0 or len(substrings) > 2:
		    continue
 		if len(substrings) == 1:
			s = substrings[0].lstrip()
			if s != "":  
				# if there is something on this line and no ":", we have a problem.
				s = s.rstrip()
				print("\nBad command \'" + s + "\' in file: " + filename)
				bad_thing_happened = True
				break
			else:
				continue
		# FIXME: 
		# We should add a check to make sure
		# the file does not try to compare files before
		# running the command, etc.

		# now try to interpret what we have.
		s = substrings[0]
		if s == "suite":
			current_suite = substrings[1].strip()
			print("Running Suite: " + current_suite + "\n")
		if s == "command":
			os.system(substrings[1])
		if s == "compare":
			total_comparisons += 1
			st = substrings[1]
			st = st.lstrip()
			st = st.rstrip()
			filenames = st.split(",")
			if len(filenames) < 2:
				print("Error while attempting to compare files")
				print("Filecount was too small")
			file1 = filenames[0]
			file2 = filenames[1].lstrip()
			# FIXME
			# make sure these files actually exist
			# before doing the comparison.
			# ALSO, IS THERE A WAY TO CATCH ERRORS?
			if is_verbose == True:
				sys.stdout.write("Comparing: " + file1 + " " + file2)			
			result = fc.cmp(file1, file2)
			if result == False:	 
				sys.stdout.write(" *** TEST FAILED ***\n")
				failures += 1
			else:
				sys.stdout.write("\n")

	if bad_thing_happened == True:
		print("")
		print("*** Error while Running the \'" + current_suite + "\' Suite, Tests not complete!")
	else:
		print("\nSummary:")
		print("\tRan a total of " + str(total_comparisons) + " comparisons")
		print("\tThere was " + str(failures) + " failure(s)")

	print("")
