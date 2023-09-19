/** Multiple Timing System example
*/
#include <rcc_stdlib.h>
using namespace std;

int main(void)
{
  stdio_init_all(); //Initialize Serial communications (usb vs gpio set in CMakeLists.txt)

  uint32_t current_time; // The "current" time at the beginning of each interation of the loop

  // Timing System 0
  int state0;
  uint32_t prev_time0;
  double duration0 = 0.856;

  // Timing System 1
  int state1;
  uint32_t prev_time1;
  double duration1 = 1.0;

  // Timing System 2
  int state2;
  uint32_t prev_time2;
  double duration2 = 0.335;

  // Initialize state and timing variables
  state0 = 0;
  state1 = 0;
  state2 = 0;
  current_time = time_us_32();
  prev_time0 = current_time;
  prev_time1 = current_time;
  prev_time2 = current_time;

  while (true)
  {
  // Timing System 0-----------------------------------------------------------
    // State 0
    if (state0 == 0)
    {
      // update current time
      current_time = time_us_32();
      // Check if transition condition is met
      if ((current_time - prev_time0) >= duration0 * 1000000.0)
      {
        // Time has exceeded duration move to state 1
        state0 = 1;
      }
    }

    // State 1
    if (state0 == 1)
    {
      // Execute and reset timing variables and reset to state 0
      cout << "Execute 0\n";
      prev_time0 = current_time;
      state0 = 0;
    }

  // Timing System 1-----------------------------------------------------------
    // State 0
    if (state1 == 0)
    {
      // update current time
      current_time = time_us_32();
      // Check if transition condition is met
      if ((current_time - prev_time1) >= duration1 * 1000000.0)
      {
        // Time has exceeded duration move to state 1
        state1 = 1;
      }
    }

    // State 1
    if (state1 == 1)
    {
      // Execute and reset timing variables and reset to state 0
      cout << "Execute 1\n";
      prev_time1 = current_time;
      state1 = 0;
    }

  // Timing System 2-----------------------------------------------------------
    // State 0
    if (state2 == 0)
    {
      // update current time
      current_time = time_us_32();
      // Check if transition condition is met
      if ((current_time - prev_time2) >= duration2 * 1000000.0)
      {
        // Time has exceeded duration move to state 1
        state2 = 1;
      }
    }

    // State 1
    if (state2 == 1)
    {
      // Execute and reset timing variables and reset to state 0
      cout << "Execute 2\n";
      prev_time2 = current_time;
      state2 = 0;
    }
  }
}