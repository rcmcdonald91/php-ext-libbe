--TEST--
Test libbe_activate()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_init',
	'be_create',
	'be_nextboot_name',
	'be_activate',
	'libbe_refresh',
	'be_destroy',
	'libbe_close'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest
$be = libbe_init();
$be_to_create = "libbe_ext_test".rand(0, 100);
be_create($be, $be_to_create);
$be_next_pre = be_nextboot_name($be);

// test
be_activate($be, $be_to_create);
libbe_refresh($be);
$be_next_post = be_nextboot_name($be);
var_dump($be_next_pre !== $be_next_post);

// posttest
be_activate($be, $be_next_pre);
libbe_refresh($be);
be_destroy($be, $be_to_create);
libbe_close($be);
?>
===DONE===
--EXPECTF--
bool(true)
===DONE===
