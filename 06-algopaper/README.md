### Definition of "Algorithm"

*A process or set of rules to be followed in calculations or other problem-solving operations, especially by a computer.*

Oxford dictionaries


## Exercises

Take paper and pencil and write a set of instruction for your computer.

No colors, just black and white. Focus on lines and forms for now.

- Iteration n.1
You can draw just lines, circles and boxes. To move around, use your the `moveTo` method.


- Iteration n.2
You can draw also the history of your 300 position. See `drawHistory` and `addToHistory`. The history of your pen is just an `ofPolyline`, we already did something [similar](edap/breaking-two-things-at-once/tree/master/03-lines).

- Iteration n.3
Add sin and/or cos of ofTimeGetElapsedTimef to your sketch. Change amplitude and frequency. Use `ofMap` to control your values.

- Iteration n.4
You can use also use `ofRandom`.
Try to add `ofSeedRandom((int)(ofGetElapsedTimef()*5));` before to call `ofRandom`. What is the difference?

- Iteration n.5
Add a mouse interaction and/or a keystroke interaction.

- Iteration n.6
You can use multiple pens. Even a [vector](/edap/breaking-two-things-at-once/tree/master/02-vectors) of pen.

## What did you learn
To sketch and prototype an algorithm on paper. Vector operation and forces.


## References

[Vera Molnar art](https://github.com/ofZach/dayForNightSFPC/wiki/Vera-Molnar)

[The recode project](http://recodeproject.com/)

[The nature of code, forces](http://natureofcode.com/book/chapter-2-forces/)

[Algo course by Zach Lieberman](https://github.com/edap/algo2012), just clone the repo and try out some apps.

[Graphics docs](https://openframeworks.cc/documentation/graphics/)
