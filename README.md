LeapPoint
=========

A minimalist Leap Motion control app for controlling PowerPoint on Mac


This app recognizes two gestures:

1. Swipe (must be at least 30 cm in length)
2. Circle (must be 5mm in radius and reach a full circle)

Swipe right/left means previous/last page
Circle clockwise/counter clockwise means go to end/beginning of the presentation

LeapListener class is a callback handler of Leap Motion frame events. When it detects a circle or swipe gesture, it simply calls Utilities to send keyboard events to the system (left/right arrow, home/end keys)

Utilities class contains two static function: 1) inteprete a variety of gesture 2) create keyboard events



