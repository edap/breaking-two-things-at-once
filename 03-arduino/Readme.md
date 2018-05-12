This sketch it is based on the example `examples/communication/firmataExample`.

This Example demonstrates communication with Arduino using the Firmata protocol.

Running this example requires uploading Firmata to your Arduino. With your Arduino connected, open Arduino and navigate to File -> Examples -> Firmata and open StandardFirmata. Compile and upload StandardFirmata for your board before running this application.


Connect a Potentiometer to Arduino as showed in this picture
![img](/bin/data/potentiometer.jpg)

Run the sketch, using the potentiometer you should be able to add some noise to the picture.

### What did you lear?

How to connect an openFrameworks application to the arduino board.

How to read the analog input from arduino.

How to read an `ofImage` by pixel, and how to shift its pixel using noise.

### Exercises

Can you imagine another kind of interaction using the digital input?

Could you edit the position of the vertices contained in an `ofPolyline` using the analog input?




