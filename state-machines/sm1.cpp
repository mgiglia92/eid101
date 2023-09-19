#include <rcc_stdlib.h>
using namespace std;

int main(void)
{
    stdio_init_all();
    sleep_ms(1500);
    cyw43_arch_init();
    cyw43_arch_gpio_put(0,1); //turns on LED
    rcc_init_pushbutton();

//State Transition diagram variables
    int state=0; //the 'state' we are currently in
    double duration = 1.0; //the button press duration we're looking for
    unsigned long start_time; //the time the button was first pressed
    unsigned long current_time;//the current time

    while(true){
    //State 1
        if(state == 0)
        {
            if(!gpio_get(RCC_PUSHBUTTON))
            {
            //Button has been pressed, transition to state 2,
            //set start time variable to current time
            state = 1;
            start_time = time_us_32();
            }
        }
        
    //State 2
        if(state == 1)
        {
            //Check if button is released, if so go back to state 1
            // and print "long press NOT detected"
            if(gpio_get(RCC_PUSHBUTTON)) { state = 1; cout << "long press NOT detected\n";}
            //Check if button is still pressed, if so check duration
            if(!gpio_get(RCC_PUSHBUTTON))
            {
            //Get current time
            current_time = time_us_32();
            if((current_time - start_time) >= duration*1000000.0)
            {
                //Button has been held for 1 second, move to state 3
                state = 2;
            }
            }
        }
    //State 3
        if(state == 2)
        {
            //reset back to state 1 and print "long button press detected"
            state = 0;
            cout << "long button press detected\n";
        }
    }
}