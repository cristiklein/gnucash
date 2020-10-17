/********************************************************************
 * test-autoclear.c: test suite for Auto-Clear          	    *
 * Copyright 2013 John Ralls <jralls@ceridwen.us>		    *
 *                                                                  *
 * This program is free software; you can redistribute it and/or    *
 * modify it under the terms of the GNU General Public License as   *
 * published by the Free Software Foundation; either version 2 of   *
 * the License, or (at your option) any later version.              *
 *                                                                  *
 * This program is distributed in the hope that it will be useful,  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    *
 * GNU General Public License for more details.                     *
 *                                                                  *
 * You should have received a copy of the GNU General Public License*
 * along with this program; if not, you can retrieve it from        *
 * https://www.gnu.org/licenses/old-licenses/gpl-2.0.html            *
 * or contact:                                                      *
 *                                                                  *
 * Free Software Foundation           Voice:  +1-617-542-5942       *
 * 51 Franklin Street, Fifth Floor    Fax:    +1-617-542-2652       *
 * Boston, MA  02110-1301,  USA       gnu@gnu.org                   *
 ********************************************************************/
#include <config.h>
#include <glib.h>
#include <unittest-support.h>
#include <qofbookslots.h>
#include "test-engine-stuff.h"
#include "../option-util.h"

static const gchar *suitename = "/app-utils/autoclear";

void test_suite_autoclear (void);

typedef struct
{
} Fixture;

static void
setup (Fixture *fixture, gconstpointer pData)
{
}

static void
teardown (Fixture *fixture, gconstpointer pData)
{
    test_clear_error_list();
}

static void
test_autoclear (Fixture *fixture, gconstpointer pData)
{
    g_assert (TRUE);
}

void
test_suite_autoclear (void)
{
    GNC_TEST_ADD (suitename, "Auto-clear all transactions", Fixture, NULL, setup, test_autoclear, teardown);
}
