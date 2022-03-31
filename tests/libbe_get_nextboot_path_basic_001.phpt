--TEST--
Test be_nextboot_path()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--FILE--
<?php
$be = libbe_init();
var_dump(be_nextboot_path($be));
libbe_close($be);
?>
===DONE===
--EXPECTF--
string(%d) "%s"
===DONE===
