# HammingCodeHardware
Code repository for Discrete Math Fall 2024 Final Project

## Instructions: 
*Recommended use in Arduino IDE.* 
* Open serial monitor and make sure that Arduino is connected to a serial port on your computer. 
* Set baud rate in serial monitor to 115200, or you can change it below but make sure your serial \
monitor baud rate is always equal to BAUD-RATE. 
* Send valid 4 bit message such as "1111", "0000", "1101", "0100", etc. to the serial monitor. 
* High or low value will be sent from pins 1-4 according to the message. 
* To send a new message just send a new four bit message in the serial monitor. 

## Helpful links for others:

The following is a list of resources our team found helpful to understand the math behind Hamming Codes (Linear Codes, specifically) and implement them in hardware. They are organized in the order we recommend learning the material. 

[Gilbert Strang's 18.06 Linear Algebra Lectures](https://www.youtube.com/playlist?list=PLE7DDD91010BC51F8): Lectures 6, 7, 9, 10 are helpful to review the four fundamental subspaces (row space, column space, null space, left null space) and basis, dimension, and span which are frequently used concepts in Hamming Codes. 

[eigenchris Hamming Codes Playlist](www.youtube.com/playlist?list=PLJHszsWbB6hqkOyFCQOAlQtfzC1G9sf2_): Videos 1, 2a, 2b, 2c are helpful to learn how linear algebra and mod 2 arithmetic is used to encode and decode Hamming Codes. 

[Introduce to Algebraic Coding Theory Book](http://faculty.olin.edu/sadams/eccbook2007-2.pdf): Our Professor, Sarah Spence Adams, wrote a book on Algebraic Coding Theory which she did research on for several years. We read chapters 1 and 2 to supplement our knowledge from eigenchris' videos and benchmark our understanding with practice problems. 

[Ben Eater's Hamming Codes in hardware tutorial](https://www.youtube.com/watch?v=h0jloehRKas): We relied on Ben Eater's video, exclusively, for our hardware implementation. This video builds on the math we learned using the three previous resources and provides a very helpful step-by-step guide for implementation. (Helpful tip: Test your XOR gate chips to make sure they work before you start putting them on the breadboard!)

## Team contact:
If you are curious to hear more about our implementation or would like advice on getting started with your own, our contact information is below!

Tyler Ewald: tewald@olin.edu

Zayn Patel: zpatel@olin.edu

Manual de Tezanos Pinto: mdetezanospinto@olin.edu

Tane Koh: mkoh@olin.edu
