from .instruction import *
from .function import *
from .instruction_table import *

print('client', instruction)

__all__ =  (
    instruction.__all__ +
    function.__all__ +
    instruction_table.__all__
)
