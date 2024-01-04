--TEST--
Test libbe_init()
--CREDITS--
R. Christian McDonald <rcm@rcm.sh>
--EXTENSIONS--
libbe
--FILE--
<?php
$be = libbe_init();
var_dump($be);
libbe_close($be);
?>
===DONE===
--EXPECTF--
object(LibbeHandle)#%d (%d) {
}
===DONE===
