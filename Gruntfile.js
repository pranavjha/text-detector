'use strict';
module.exports = function(grunt) {
    // loading the npm tasks
    grunt.loadNpmTasks('grunt-exec');
    grunt.loadNpmTasks('grunt-docco');
    grunt.loadNpmTasks('grunt-gh-pages');
    grunt.loadNpmTasks('grunt-mocha-test');
    grunt.loadNpmTasks('grunt-contrib-clean');
    grunt.loadNpmTasks('grunt-contrib-jshint');
    // Project configuration.
    grunt.initConfig({
            pkg: grunt.file.readJSON('package.json'),
            exec: {
                rebuild: {
                    cmd: './node_modules/.bin/node-gyp rebuild',
                    stdout: (grunt.option('debug') || false),
                    stderr: (grunt.option('debug') || false)
                }
            },
            clean: [
                '.test'
            ],
            jshint: {
                lib: {
                    src: [
                        'lib/**/*.js',
                        'Gruntfile.js',
                        'package.json'
                    ],
                    options: {
                        nonew: true,
                        plusplus: true,
                        curly: true,
                        latedef: true,
                        maxdepth: 6,
                        unused: true,
                        noarg: true,
                        trailing: true,
                        indent: 4,
                        forin: true,
                        noempty: true,
                        quotmark: true,
                        maxparams: 6,
                        node: true,
                        eqeqeq: true,
                        strict: true,
                        undef: true,
                        bitwise: true,
                        newcap: true,
                        immed: true,
                        camelcase: true,
                        maxcomplexity: 7,
                        maxlen: 120,
                        nonbsp: true,
                        freeze: true
                    }
                },
                // configuration for test files.
                test: {
                    src: [
                        'test/**/*.js'
                    ],
                    options: {
                        predef: [
                            'describe',
                            'it',
                            'beforeEach',
                            'afterEach',
                            'before',
                            'after'
                        ],
                        nonew: true,
                        plusplus: true,
                        curly: true,
                        latedef: true,
                        maxdepth: 6,
                        unused: true,
                        noarg: true,
                        trailing: true,
                        indent: 4,
                        forin: true,
                        noempty: true,
                        quotmark: true,
                        maxparams: 6,
                        node: true,
                        eqeqeq: true,
                        strict: true,
                        undef: true,
                        bitwise: true,
                        newcap: true,
                        immed: true,
                        camelcase: true,
                        maxcomplexity: 7,
                        maxlen: 120,
                        nonbsp: true,
                        freeze: true

                    }
                }
            },
            // Configure a mochaTest task
            mochaTest: {
                test: {
                    options: {
                        reporter: 'spec'
                    },
                    src: [
                        'test/*.js'
                    ]
                }
            },
            docco: {
                debug: {
                    src: [
                        'lib/**',
                        'README.md'
                    ],
                    options: {
                        output: '.docs/'
                    }
                }
            },
            'gh-pages': {
                options: {
                    base: '.docs',
                    // GH_TOKEN is the environment variable holding the access token for the repository
                    repo: 'https://' + process.env.GH_TOKEN + '@github.com/pranavjha/scene-text.git',
                    clone: '.gh_pages',
                    message: 'auto commit on <%= grunt.template.today("yyyy-mm-dd") %>',
                    // This configuration will suppress logging and sanitize error messages.
                    silent: true,
                    user: {
                        name: 'Pranav Jha',
                        email: 'jha.pranav.s@gmail.com'
                    }
                },
                src: [
                    '**'
                ]
            }
        }
    );
    grunt.registerTask('test', [
        'exec',
        'jshint',
        'mochaTest'
    ]);
    grunt.registerTask('document', [
        'docco'
    ]);
};