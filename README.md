[![Build Status](https://travis-ci.org/pranavjha/text-detector.svg)](https://travis-ci.org/pranavjha/text-detector)
[![Code Climate](https://codeclimate.com/github/pranavjha/text-detector/badges/gpa.svg)](https://codeclimate.com/github/pranavjha/text-detector)

[![Dependency Status](https://david-dm.org/pranavjha/text-detector.svg)](https://david-dm.org/pranavjha/text-detector)
[![devDependency Status](https://david-dm.org/pranavjha/text-detector/dev-status.svg)](https://david-dm.org/pranavjha/text-detector#info=devDependencies)
[![peerDependency Status](https://david-dm.org/pranavjha/text-detector/peer-status.svg)](https://david-dm.org/pranavjha/text-detector#info=peerDependencies)


# text-detector

> native node module for scene text recognition using tesseract and openCV

`text-detector` is a native nodejs module for extracting text from real-life photographs and scenes.


## How to use


``` javascript

var textDetector = require('text-detector');

// synchronous API

// detects text in the image at the given path.
var text = textDetector.getTextSync('/sample/path/to/a/file');

// skip the region detection
var text = textDetector.getTextSync('/sample/path/to/a/file', false);

// asynchronous API

// detects text in the image at the given path.
textDetector.getText('/sample/path/to/a/file', function (err, text) {
    // do something with the text here
});

// skip the region detection
textDetector.getText('/sample/path/to/a/file', true, function (err, text) {
    // do something with the text here
});

```


