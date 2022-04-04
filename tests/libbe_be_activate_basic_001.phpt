--TEST--
Test libbe_refresh() with be_activate()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
if (!function_exists('be_activate'))
	print "skip";
?>
--FILE--
<?php
$be = libbe_init();
$be_to_create = "libbe_ext_test".rand(0, 100);
be_create($be, $be_to_create);
$be_next_pre = be_nextboot_name($be);
be_activate($be, $be_to_create);
libbe_refresh($be);
$be_next_post = be_nextboot_name($be);
var_dump($be_next_pre !== $be_next_post);
be_activate($be, $be_next_pre);
libbe_refresh($be);
be_destroy($be, $be_to_create);
?>
===DONE===
--EXPECTF--
bool(true)
===DONE===
