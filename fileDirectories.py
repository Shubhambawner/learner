import os
subdirs = [x[0] for x in os.walk('.')]
print(subdirs)