/*************************************************************************
**									**
**  Description 							**
**									**
** This file contains functions which generate basic evolution matrices	**
** for use in magnetization vector evolution under the phenomenological	**
** Bloch equations. In the simplest case the returned array will be	**
** a 3x3 matrix which appears as					**
**									**
**          [        0          -w + w       g*B  * sin(phi) ]		**
**          |                     0   rf        1            |		**
**          |                                                |		**
**      B = |     w - w             0       -g*B  * cos(phi) |		**
**          |      0   rf                       1            |		**
**          |                                                |		**
**          [ -gB * sin(phi)   gB * cos(phi)       0         |		**
**          [    1               1                           ]		**
**                                                  t			**
** and this will act on the magnetization vector |M> = [Mx My Mz].	**
** In a more general context, the above array will be a single block	**
** on the diagonal of a larger matrix of dimension 3N x 3N where N is	**
** the number of sub-vectors in a general magnetization vector . In	**
** that case, the array appears as					**
**									**
**                        [ [B ]  0    0   . . .   0    ]		**
**                        | [ 0]                        |		**
**                        |      [B ]  0   . . .   0    |		**
**                        |  0   [ 1]                   |		**
**                        |           [B ] . . .   0    |		**
**                    B = |  0    0   [ 2]              |		**
**                        |                . . .   0    |		**
**                        |  .    .    .   . . .        |		**
**                        |  .    .    .   . . .   0    |		**
**                        |  .    .    .   . . .        |		**
**                        |                . . . [B   ] |		**
**                        [  0    0    0   . . . [ N-1] ]		**
**									**
**                                             t			**
** and will act on the magnetization vector |M> = ||M >|M >....|M   >.	**
**                                                   0	 1       N-1	**
**									**
*************************************************************************/


