/********************************* TRICK HEADER *******************************
PURPOSE:
    (Ball::state_init performs the following:
        - passes the input position vector to the output vector
        - xforms the input ball speed and trajectory elevation into a
          velocity vector.)
REFERENCE:
    (((Bailey, R.W, and Paddock, E.J.)
      (Trick Simulation Environment) (NASA:JSC #37943)
      (JSC/Engineering Directorate/Automation, Robotics and Simulation Division)
      (March 1997)))
ASSUMPTIONS AND LIMITATIONS:
    ((2 dimensional space)
     (Positive X is horizontal to the right)
     (Positive Y is vertical and up))
CLASS:
    (initialization)
LIBRARY DEPENDENCY:
    ((BallStateInit.o))
PROGRAMMERS:
    (((Robert W. Bailey) (Sweet Systems Inc) (March 1997) (Tutorial Lesson 1))
     ((Edwin Z. Crues)(Titan Systems Corp.)(Jan 2002)(Crude C++ translation)))
*******************************************************************************/

/*
  * $Id: BallStatePrint.cpp 1633 2011-05-20 16:38:11Z lin $
 *
 * Revision 5.1  2004-08-05 13:06:22-05  lin
 * Bump
 *
 * Revision 4.1  2003/10/21 21:49:41  lin
 * Bump version number for 04
 *
 * Revision 1.2  2002/10/07 15:15:56  lin
 * Add rcs version info to all trick_models files
 *
 */

/* System include files. */
#include <math.h>
#include <iostream>
#include <unistd.h>

/* Model include files. */
#include "../include/Ball.hh"
#include "sim_services/Executive/include/exec_proto.hh"
#include "sim_services/Executive/include/exec_proto.h"
#include "sim_services/Message/include/message_proto.h"

     /* ENTRY POINT */
int Ball::state_print() {

   message_publish(MSG_NORMAL, "time = %8.2f , position = %12.6f , %12.6f\n",
    exec_get_sim_time() , state.output.position[0] , state.output.position[1]) ;

   /* RETURN */
   return( 0 );

}

