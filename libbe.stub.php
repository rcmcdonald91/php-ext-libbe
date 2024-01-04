<?php

/** @generate-class-entries */

/**
 * @var int
 * @cvalue BE_ERR_SUCCESS
 */
const BE_ERR_SUCCESS = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_INVALIDNAME
 */
const BE_ERR_INVALIDNAME = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_EXISTS 
 */
const BE_ERR_EXISTS = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_NOENT
 */
const BE_ERR_NOENT = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_PERMS
 */
const BE_ERR_PERMS = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_DESTROYACT
 */
const BE_ERR_DESTROYACT = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_DESTROYMNT
 */
const BE_ERR_DESTROYMNT = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_BADPATH
 */
const BE_ERR_BADPATH = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_PATHBUSY
 */
const BE_ERR_PATHBUSY = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_PATHLEN
 */
const BE_ERR_PATHLEN = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_BADMOUNT
 */
const BE_ERR_BADMOUNT = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_NOORIGIN
 */
const BE_ERR_NOORIGIN = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_MOUNTED
 */
const BE_ERR_MOUNTED = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_NOMOUNT
 */
const BE_ERR_NOMOUNT = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_ZFSOPEN
 */
const BE_ERR_ZFSOPEN = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_ZFSCLONE
 */
const BE_ERR_ZFSCLONE = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_IO
 */
const BE_ERR_IO = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_NOPOOL
 */
const BE_ERR_NOPOOL = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_NOMEM
 */
const BE_ERR_NOMEM = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_UNKNOWN
 */
const BE_ERR_UNKNOWN = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_INVORIGIN
 */
const BE_ERR_INVORIGIN = UNKNOWN;

/**
 * @var int
 * @cvalue BE_ERR_HASCLONES
 */
const BE_ERR_HASCLONES = UNKNOWN;

/**
 * @var int
 * @cvalue BE_DESTROY_FORCE
 */
const BE_DESTROY_FORCE = UNKNOWN;

/**
 * @var int
 * @cvalue BE_DESTROY_ORIGIN
 */
const BE_DESTROY_ORIGIN = UNKNOWN;

/**
 * @var int
 * @cvalue BE_DESTROY_AUTOORIGIN
 */
const BE_DESTROY_AUTOORIGIN = UNKNOWN;

/**
 * @var int
 * @cvalue BE_MNT_FORCE
 */
const BE_MNT_FORCE = UNKNOWN;

/**
 * @var int
 * @cvalue BE_MNT_DEEP
 */
const BE_MNT_DEEP = UNKNOWN;

/**
 * @strict-properties
 * @not-serializable
 */
final class LibbeHandle
{
}

/** @refcount 1 */
function libbe_init(?string $root = null): LibbeHandle|false {}

function libbe_close(LibbeHandle $handle): void {}

function be_active_name(LibbeHandle $handle): string {}

function be_active_path(LibbeHandle $handle): string {}

function be_nextboot_name(LibbeHandle $handle): string {}

function be_nextboot_path(LibbeHandle $handle): string {}

function be_root_path(LibbeHandle $handle): string {}

function be_snapshot(LibbeHandle $handle, string $be_name, string|null $snap_name, bool $recursive, string|null &$result = null): int {}

function be_is_auto_snapshot_name(LibbeHandle $handle, string $snap_name): bool {}

function be_create(LibbeHandle $handle, string $be_name): int {}

function be_create_depth(LibbeHandle $handle, string $be_name, string $snap_name, int $depth): int {}

function be_create_from_existing(LibbeHandle $handle, string $be_name, string $be_origin): int {}

function be_create_from_existing_snap(LibbeHandle $handle, string $be_name, string $snap_name): int {}

function be_rename(LibbeHandle $handle, string $be_name_old, string $be_name_new): int {}

function be_activate(LibbeHandle $handle, string $be_name, bool $temporary): int {}

function be_deactivate(LibbeHandle $handle, string $be_name, bool $temporary): int {}

function be_destroy(LibbeHandle $handle, string $be_name, int $options): int {}

function be_nicenum(int $num): int {}

function be_mount(LibbeHandle $handle, string $be_name, string|null $mount_point, int $flags, string|null &$result = null): int {}

function be_mounted_at(LibbeHandle $handle, string $path, array|null &$details = null): int {}

function be_unmount(LibbeHandle $handle, string $be_name, int $flags): int {}

function libbe_errno(LibbeHandle $handle): int {}

function libbe_error_description(LibbeHandle $handle): string {}

function libbe_print_on_error(LibbeHandle $handle, bool $doprint): void {}

function be_root_concat(LibbeHandle $handle, string $be_name, string &$result): int {}

function be_validate_name(LibbeHandle $handle, string $be_name): int {}

function be_validate_snap(LibbeHandle $handle, string $snap_name): int {}

function be_exists(LibbeHandle $handle, string $be_name): int {}

/** @param resource $stream */
function be_export(LibbeHandle $handle, string $be_name, $stream): int {}

/** @param resource $stream */ 
function be_import(LibbeHandle $handle, string $be_name, $stream): int {}

function be_get_bootenv_props(LibbeHandle $handle, array &$be_list): int {}

function be_get_dataset_props(LibbeHandle $handle, string $ds_name, array &$props): int {}

function be_get_dataset_snapshots(LibbeHandle $handle, string $ds_name, array &$snap_list): int {}
