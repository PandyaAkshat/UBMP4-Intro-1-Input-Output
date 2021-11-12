/*==============================================================================
 Project: Intro-1-Input-Output
 Date:    May 16, 2021
 
 This example UBMP4 input and output program demonstrates pushbutton input, LED
 (bit) output, port latch (byte) output, time delay functions, and simple 'if'
 condition structures.
 
 Additional program analysis and programming activities demonstrate byte output,
 logical condition operators AND and OR, using delay functions to create sound,
 and simulated start-stop button functionality.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// The main function is required, and the program begins executing from here.

int main(void)
{
    // Configure oscillator and I/O ports. These functions run once at start-up.
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    // Code in this while loop runs repeatedly.
    while(1)
	{
        // If SW2 is pressed, make a flashy light pattern
        if(SW2 == 0)
        {
            LED3 = 1;
            __delay_ms(100);
            LED4 = 1;
            __delay_ms(100);
            LED5 = 1;
            __delay_ms(100);
            LED6 = 1;
            __delay_ms(100);
            LED3 = 0;
            __delay_ms(100);
            LED4 = 0;
            __delay_ms(100);
            LED5 = 0;
            __delay_ms(100);
            LED6 = 0;
            __delay_ms(100);
        }
        
        // Add code for your Program Analysis and Programming Activities here:
        // If SW3 is pressed, make a flashy light pattern
        if(SW3 == 0)
        {
            LED4 = 1;
            __delay_ms(100);
            LED6 = 1;
            __delay_ms(100);
            LED5 = 1;
            __delay_ms(100);
            LED3 = 1;
            __delay_ms(100);
            LED4 = 0;
            __delay_ms(100);
            LED6 = 0;
            __delay_ms(100);
            LED5 = 0;
            __delay_ms(100);
            LED3 = 0;
            __delay_ms(100);
        }

         // If SW5 is pressed, make a flashy light pattern
        if(SW5 == 0)
        {
            LED6 = 1;
            __delay_ms(100);
            LED3 = 1;
            __delay_ms(100);
            LED6 = 0;
            __delay_ms(100);
            LED3 = 0;
            __delay_ms(100);
            LED5 = 1;
            __delay_ms(100);
            LED4 = 1;
            __delay_ms(100);
            LED5 = 0;
            __delay_ms(100);
            LED4 = 0;
            __delay_ms(100);
            LED5 = 1;
            __delay_ms(100);
            LED6 = 1;
            __delay_ms(100);
            LED5 = 0;
            __delay_ms(100);
            LED6 = 0;
            __delay_ms(100);
            LED4 = 1;
            __delay_ms(100);
            LED3 = 1;
            __delay_ms(100);
            LED4 = 0;
            __delay_ms(100);
            LED3 = 0;
            __delay_ms(100);
        }

        // If SW4 is pressed, make a flashy light pattern
       if(SW4 == 0)
       { 
            LED4 = 1;
            __delay_ms(100);
            LED4 = 0;
            __delay_ms(100);
            LED5 = 1;
            __delay_ms(100);
            LED5 = 0;
            __delay_ms(100);
            LED3 = 1;
            __delay_ms(100);
            LED3 = 0;
            __delay_ms(100);
            LED6 = 1;
            __delay_ms(100);
            LED6 = 0;
            __delay_ms(100);
            LED4 = 1;
            LED5 = 1;
            LED3 = 1;
            LED6 = 1;
            __delay_ms(100);
            LED4 = 0;
            LED5 = 0;
            LED3 = 0;
            LED6 = 0;
            __delay_ms(100);
              LED4 = 1;
            LED5 = 1;
            LED3 = 1;
            LED6 = 1;
            __delay_ms(100);
            LED4 = 0;
            LED5 = 0;
            LED3 = 0;
            LED6 = 0;
            __delay_ms(100);
       }

        //Stop and start buttons.
        if(SW3 == 0 && SW4 == 1)
        {
            LED4 = 1;
        }
        if(SW4 == 0)
        {
            LED4 = 0;
        }

        //LED 1 flashing
        if(SW5 == 0)
        {
            LED1 = 0;
            __delay_ms(107);
            LED1 = 1;
            __delay_ms(107);
            LED1 = 0;
            __delay_ms(107);
            LED1 = 1;
            __delay_ms(107);
            LED1 = 0;
            __delay_ms(107);
            LED1 = 1;
            __delay_ms(107);
        }       
     
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

/* Program Analysis
 * 
 * 1. How many times do the LEDs flash if SW2 is quickly pressed and released?
 *    Do the LEDs keep flashing when SW2 is held? Look at the program and
 *    explain why this happens when SW2 is held.
 Each LED flashes once if SW2 is pressed and released quickly. The LEDS keep flashing in a loop if you hold SW2 and this
 happens because the code is in a while loop which is a repeating statement so it is constantly checking if SW2 is pressed and
 if it is then it runs the light pattern each time.
 * 
 * 2. Explain the difference between the statements: LED3 = 0; and LED3 = 1;
 The difference is that one states LED3 turns off (0) or LED turns on (1) in binary language.
 * 
 * 3. What voltage do you expect the microcontroller to output to LED D3 when
 *    the statement LED3 = 0; runs? What voltage do you expect the output to be
 *    when the statement LED3 = 1; runs?

    I predict the statement LED3 = 0; would make it so NO voltage would output to LED D3 and LED3 = 1; would make it so 5 volts 
    would be outputed

 * 
 *    You can confirm the output voltage with a voltmeter if you have access
 *    to one. If you tried that, did the voltage match your prediction?
      
 * 
 * 4. The statement 'if(SW2 == 0)' uses two equal signs, while the statement
 *    'LED3 = 1;' uses a single equal sign. What operation is performed by one
 *    equal sign? What operation is performed by two equal signs?
     
     The double equal sign is a conditional operator and the single equal sign is a assignment operator
 * 
 * 5. The following program code includes instructions that write to the PORTC
 *    output latches directly. Try it by copying and pasting this code below
 *    the existing SW2 'if' structure, at the location shown by the comment.

        if(SW3 == 0)
        {
            LATC = 0b00000000;
            __delay_ms(100);
            LATC = 0b11110000;
            __delay_ms(100);
        }

 *    What happens when pushbutton SW3 is pressed? Identify at least one
 *    advantage and one disadvantage of controlling the LEDs using 'LATC' writes
 *    rather than through individual 'LEDn = x;' statements.
           
     When SW3 is pushed, LED's turn on and stay on. One advantage of using 'LATC' is that it uses less lines of code. One disadvantage
     is that when we use 'LATC' we dont know what is using the pins the LED's are connected to so in the process we don't know what else we are messing with.
 * 
 * 6. Next, compare the operation of 'if' and 'while' structures to simulate
 *    momentary buttons. Replace the code you added in 5, above, with this code:

        // Momentary button using if structure
        if(SW3 == 0)
        {
            LED4 = 1;
        }
        else
        {
            LED4 = 0;
        }

        // Momentary button using while structure
        while(SW4 == 0)
        {
            LED5 = 1;
        }
        LED5 = 0;

 *    First, try pressing and releasing SW3 and SW4 one at a time.
 * 
 *    Next, press and hold SW3 while pressing and releasing SW4. Does it work
 *    as expected?
    Yes, SW3 and SW4 are both momentary buttons that only stay on while the button is actually pressed.
 * 
 *    Next, try press and holding SW4 while pressing and releasing SW3. Does it
 *    work as expected? Explain the difference in operation between the 'if' and
 *    'while' structures making up the momentary button code.

 No, when SW4 is pressed and held SW3 does not turn on when you press it. The 'if' is checked once and does something once
 whereas the 'while' is being check constantly, so it constantly checks SW4 whereas 'if' checks SW3 once.
 * 
 * 7. Let's explore logical conditions using 'if' statements. Replace the code
 *    added in 6, above, with this nested if code to make a logical AND
 *    condition that will light LED D4 only if both SW3 and SW4 are pressed:

        // Nested if 'AND' code
        if(SW3 == 0)
        {
            if(SW4 == 0)
            {
                LED4 = 1;
            }
            else
            {
                LED4 = 0;
            }
        }
        else
        {
            LED4 = 0;
        }

 *    Test the code to ensure it works as expected. Does the order of the if
 *    conditions matter? (eg. swap the conditional checks for SW3 and SW4)

      The order doesn't matter, it works as intended.
 * 
 * 8. Next, replace the code from 7 with the following code which implements a
 *    logical AND conditional operator composed of two ampersands '&&':
 
        // Conditional 'AND' code
        if(SW3 == 0 && SW4 == 0)
        {
            LED4 = 1;
        }
        else
        {
            LED4 = 0;
        }

 *    Does '&&' work the same way as the nested if structures? Can you think of
 *    at least one advantage of using a logical conditional operator instead of
 *    nested if structures?

      It does work the same way as the nested if stucture. One advantage is that a logical condtional operator uses less
      lines of code compared to the nested if structure, so it is faster.
 * 
 * 9. Replace the double ampersand '&&' with double vertical bars '||)' to make
 *    a logical OR conditional operator. Your code should look like this:
  
        // Conditional 'OR' code
        if(SW3 == 0 || SW4 == 0)
        {
            LED4 = 1;
        }
        else
        {
            LED4 = 0;
        }

 *    Describe the conditions under which LED4 turns on.
 * 
     LED4 turns on if SW3 is pressed/held or if SW4 is pressed/held, or if both are pressed and held.
 * 
 * Programming Activities
 * 
 * 1. The statement '__delay_ms(100);' creates a 100ms delay. Try changing one
 *    or more of the delay values in the program to 500ms and see what happens.
      
      It creates a huge delay in which ever of the LED's delays you changed
 * 
 *    Can the delay be made even longer? Try 1000 ms. How big can the delay be
 *    before MPLAB-X produces an error message? (Hint: can you think of a fast
 *    and efficient way of guessing an unknown number?)

     The delay can be 1000 ms but cannot exceed 10000 ms.
 * 
 * 2. The '__delay_ms();' function only accepts integers as delay values. To
 *    make delays shorter than 1ms, specify a delay in microseconds using the
 *    '__delay_us();' function. You won't be able to see such short LED flashes
 *    with your eyes, but you could measure them using an oscilloscope, or hear
 *    them if they are used to turn the piezo beeper on and off. Try this code:
 
        // Make a tone while SW5 is held
        if(SW5 == 0)
        {
            BEEPER = 1;
            __delay_us(567);
            BEEPER = 0;
            __delay_us(567);
        }

 *    Try changing the delay values in both of the __delay_us(); functions.
 *    Does the pitch of the tone increase or decrease if the delay value is
 *    made smaller?

      A smaller delay value makes the pitch of the tone higher.
 * 
 * 3. This code demonstrates a more compact way of toggling the beeper output
 *    using a logical NOT operator '!'. Replace the code above, with this code:
 
        // Make a tone while SW5 is held
        if(SW5 == 0)
        {
            BEEPER = !BEEPER;
            __delay_us(567);
        }

 *    One difference between this code and the code in 2, above, is the state
 *    of the BEEPER pin when SW5 is released. What state will the BEEPER output
 *    be in after this code runs? While one advantage of this method is smaller
 *    code, can you think of one or more disadvantages based on its output when
 *    the button is released?

      The beeper pin will be 1. One disadvantage of this method could be that when the output is left as one, the code is checking for if SW5 is 0. 
 * 
 * 4. Using modified versions of the original SW2 'if' structure, create a
 *    program that makes a unique LED flashing pattern for each pushbutton.
 * 
 *    Test each of your flashing patterns. Describe what happens when more than
 *    one button is held. Do all of the patterns try to flash the LEDs at the
 *    same time, or sequentially? Explain why this is.
 * 
       The patterns happen sequentially and not all at the same time. I think this happens because the program does your commands
       in whatever order you wrote them, if pattern 1 comes before pattern two in the code then it will do pattern 1 first like it was told to do.
 * 5. Create a program that makes a different tone for each pushbutton.
 * 
 *    Test each tone by pressing each button individually. Next, press two or
 *    more buttons at the same time. Describe what the tone waveform would look
 *    like when more than one button is held.

      It would look like a constant line. when more than one button is pressed the beeper creates one constant sound that only changes
      when you let go of one of the buttons.
 * 
 * 6. Use individual 'if' structures to simulate 'Start' and 'Stop' buttons for
 *    an industrial machine. LED D4 should turn on when SW3 is pressed, stay on
 *    even after SW3 is released, and turn off when SW4 is pressed. Test your
 *    program to make sure it works.
 * 
 * 7. Running your program from 6, above, describe what happens when both SW3
 *    and SW4 are pressed. Does LED D4 stay on? If so, how does the brightness
 *    of LED D4 compare between its normal on state following SW3 being pressed
 *    to this new state when both SW3 and SW4 are bing held? Can you explain
 *    why it changes?

      The light gets noticeably dimmer when you press both switches at the same time. It changes because when you press both at the same time 
      it starts to turn it on and turn it off very quickly before the LED can turn on fully.
 * 
 * 8. As you can imagine, an industrial machine that is able to turn on even
 *    while its 'Stop' button is pressed represents a significant safety hazard.
 *    Using a logical conditional operator, modify the start-stop program from
 *    activity 5 to make it safer. SW3 should only turn on LED D4 if SW4 is
 *    released.
 * 
 * 9. LED D1 is normally used to indicate that a program is running, but it can
 *    be controlled by your program as well. If you take a look at the UBMP4
 *    schematic, you will see that LED D1's cathode (or negative) pin is
 *    connected to the microcontroller instead of the anode (positive) pin as
 *    with the other LEDs. This means that you need to make D1's output a zero
 *    to turn D1 on. Try it! Make a program that controls or flashes LED D1.
 */
