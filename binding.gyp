{
  "targets": [{
    "target_name": "graph",
	"sources": [ "main.cpp", "node.cpp", "edge.cpp", "graph.cpp"],
	'cflags!': [ '-fno-exceptions' ],
	'cflags_cc!': [ '-fno-exceptions' ],
	'conditions': [
		['OS=="mac"', {
		  'xcode_settings': {
		    'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
		  }
		}]
	]
  }]
}
