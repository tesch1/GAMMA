# SWIG creates a Python wrapper with the same name as our package (pygamma)
# and as a result the correct way to import it would be like so:
#    import pygamma.pygamma

# This isn't difficult but the duplication is kinda pointless so here we
# move the entire pygamma namespace up into this level which allows users
# to simply `import pygamma`

from __future__ import division

from pygamma import *
del pygamma

