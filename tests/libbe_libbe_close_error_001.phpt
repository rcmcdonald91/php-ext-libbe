--TEST--
Test libbe_close() with invalid argument (int)
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--FILE--
<?php
$be = 42;
libbe_close($be);
?>
===DONE===
--EXPECTF--
Warning: libbe_close() expects parameter 1 to be LibbeHandle, int given in %s on line %d
===DONE===
