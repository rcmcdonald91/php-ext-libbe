--TEST--
Test be_active_name()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--FILE--
<?php
$be = libbe_init();
var_dump(be_active_name($be));
libbe_close($be);
?>
===DONE===
--EXPECTF--
string(%d) "%s"
===DONE===
