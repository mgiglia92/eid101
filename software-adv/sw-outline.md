# Advanced Software Outline
- Compile and explain the using-robot-examples examples such as potentiometer,button,led
- Show two examples:
    - Use the button to print two different things
    - Use the potentiometer to print two different things
## Activity:
- Have the pico print "SOMETHING~" only when the button is pressed and the potentiometer is near the middle of it's adjustability
## Challenge: 
- Set the state of the LED ONLY when the button is pressed. The state of the LED is defined by sectioning the potentiomete values into two sections. One section is ON the other is OFF.
    - Make the above "cleaner" by doing the following:
        - Make a struct that will house both the potentiometer value and the button state. Give it a good name
        - Make a function that will accept a pointer to this struct as it's only input argument
        - This function will update the pot and button vals in the struct (that was passed as a pointer)
        - Make ANOTHER function that will accept a pointer to your struct. This function will update the state of the LED depending on the pot and button values in the struct
        - Do this update every 100ms