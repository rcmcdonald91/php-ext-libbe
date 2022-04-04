--TEST--
Test libbe_refresh()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--FILE--
<?php
$be = libbe_init();
libbe_refresh($be);
var_dump($be);
?>
===DONE===
--EXPECTF--
object(LibbeHandle)#%d (%d) {
}
===DONE===
