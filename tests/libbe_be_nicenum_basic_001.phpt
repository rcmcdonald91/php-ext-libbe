--TEST--
Test be_nicenum()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'be_nicenum'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest

// test
var_dump(be_nicenum(0));
var_dump(be_nicenum(500));
var_dump(be_nicenum(1000));
var_dump(be_nicenum(15000));
var_dump(be_nicenum(1500000));
var_dump(be_nicenum(1500000000));
var_dump(be_nicenum(1500000000000));
var_dump(be_nicenum(150000000000000));

// postest
?>
===DONE===
--EXPECT--
string(1) "0"
string(3) "500"
string(4) "1000"
string(5) "14.6K"
string(5) "1.43M"
string(5) "1.40G"
string(5) "1.36T"
string(4) "136T"
===DONE===
