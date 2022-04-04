--TEST--
Test libbe_init()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--FILE--
<?php
var_dump(libbe_init());
?>
===DONE===
--EXPECTF--
object(LibbeHandle)#%d (%d) {
}
===DONE===
