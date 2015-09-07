'use strict';
var addon = require('../lib');
var expect = require('chai').expect;

describe('functionality', function() {
    it('should be able to decode an image', function() {
        var calculations = 100;
        var result = addon.calculateSync(calculations);
        expect(Math.floor(result)).to.eql(3);
    });
});
