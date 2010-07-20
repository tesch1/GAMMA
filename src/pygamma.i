%module pygamma

%pythoncode %{
__version__ = "4.2.0"
%}


%include "Basics/basics.i"
%include "Matrix/matrix_inc.i"
%include "HSLib/hslib.i"
%include "LSLib/lslib.i"
%include "Level2/level2.i"
%include "Pulses/pulses.i"


