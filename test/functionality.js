'use strict';
var sceneText = require('../lib');
var expect = require('chai').expect;

describe('functionality', function() {

    describe('sync', function() {

        it('should be able to run', function() {
            var result = sceneText.getTextSync('/sample/path/to/a/file');
		console.log(JSON.stringify(result));
	            expect(result.box[0]).to.eql(1);
	});

        it('should be able to skip region detection', function() {
           // var result = sceneText.getTextSync('/sample/path/to/a/file');
           // expect(result).to.eql('skip/sample/path/to/a/file');
        });

        it('should be able to force region detection', function() {
            //var result = sceneText.getTextSync('/sample/path/to/a/file', true);
            //expect(result).to.eql('/sample/path/to/a/file');
        });
    });

    describe('async', function() {

        it('should be able to run', function(done) {
            sceneText.getText('/sample/path/to/a/file',[1,2,3,4], function(err, result) {
                console.log(JSON.stringify(result));
                done(err);
            });
        });

        it('should be able to skip region detection', function(done) {
            sceneText.getText('/sample/path/to/a/file', false, function(err, result) {
               console.log(JSON.stringify(result));
		// expect(result).to.eql('skip/sample/path/to/a/file');
                done(err);
            });
        });

        it('should be able to force region detection', function(done) {
            sceneText.getText('/sample/path/to/a/file', true, function(err, result) {
                console.log(JSON.stringify(result));
    		//expect(result).to.eql('/sample/path/to/a/file');
                done(err);
            });
        });
    });
});
