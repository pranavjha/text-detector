'use strict';
var sceneText = require('../lib');
var expect = require('chai').expect;

describe('functionality', function() {
    it('should be able to run in sync mode', function() {
        var result = sceneText.getTextSync('/sample/path/to/a/file');
        expect(result).to.eql('/sample/path/to/a/file');
    });
    it('should be able to run in async mode', function(done) {
        sceneText.getText('/sample/path/to/a/file', function(err, result) {
            expect(result).to.eql('/sample/path/to/a/file');
            done(err);
        });
    });
});
