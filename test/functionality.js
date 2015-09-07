'use strict';
var addon = require('../lib');
var expect = require('chai').expect;

describe('functionality', function() {
    it('should be able to run in sync mode', function() {
        var calculations = 100;
        var result = addon.calculateSync(calculations);
        expect(Math.floor(result)).to.eql(3);
    });
    it('should be able to run in async mode', function(done) {
        var calculations = 100;
        addon.calculateAsync(calculations, function(err, result) {
            expect(Math.floor(result)).to.eql(3);
            done(err);
        });
    });
});
