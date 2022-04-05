--TEST--
Test libbe_version()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_version'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest

// test
var_dump(libbe_version());

// posttest
?>
===DONE===
--EXPECTF--
string(%d) "%d.%d.%d"
===DONE===
