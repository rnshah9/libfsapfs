/*
 * Snapshot functions
 *
 * Copyright (C) 2018-2019, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFSAPFS_SNAPSHOT_H )
#define _LIBFSAPFS_SNAPSHOT_H

#include <common.h>
#include <types.h>

#include "libfsapfs_extern.h"
#include "libfsapfs_io_handle.h"
#include "libfsapfs_libbfio.h"
#include "libfsapfs_libcerror.h"
#include "libfsapfs_libcthreads.h"
#include "libfsapfs_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfsapfs_internal_snapshot libfsapfs_internal_snapshot_t;

struct libfsapfs_internal_snapshot
{
	/* The IO handle
	 */
	libfsapfs_io_handle_t *io_handle;

	/* The file IO handle
	 */
	libbfio_handle_t *file_io_handle;

#if defined( HAVE_LIBFSAPFS_MULTI_THREAD_SUPPORT )
	/* The read/write lock
	 */
	libcthreads_read_write_lock_t *read_write_lock;
#endif
};

int libfsapfs_snapshot_initialize(
     libfsapfs_snapshot_t **snapshot,
     libfsapfs_io_handle_t *io_handle,
     libbfio_handle_t *file_io_handle,
     libcerror_error_t **error );

LIBFSAPFS_EXTERN \
int libfsapfs_snapshot_free(
     libfsapfs_snapshot_t **snapshot,
     libcerror_error_t **error );

int libfsapfs_internal_snapshot_open_read(
     libfsapfs_internal_snapshot_t *internal_snapshot,
     libbfio_handle_t *file_io_handle,
     off64_t file_offset,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFSAPFS_SNAPSHOT_H ) */

