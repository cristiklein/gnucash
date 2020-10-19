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
#include <stdlib.h>
#include <unittest-support.h>
#include <qofbookslots.h>
#include "test-engine-stuff.h"
#include "../option-util.h"

#include "test-stuff.h"

#define GNC_LIB_NAME "gncmod-backend-xml"
#define GNC_LIB_REL_PATH "xml"

static const gchar *suitename = "/app-utils/autoclear";

void test_suite_autoclear (void);

const char *TEST_FILENAME = "test-files/autoclear.gnucash";

typedef struct
{
    QofSession *session;
} Fixture;

static void
setup (Fixture *fixture, gconstpointer pData)
{
    fixture->session = qof_session_new (NULL);
    system("pwd; ls -l; ls -l test-files");

    qof_session_begin (fixture->session, TEST_FILENAME, SESSION_NORMAL_OPEN);

    qof_session_load (fixture->session, NULL);
}

static void
teardown (Fixture *fixture, gconstpointer pData)
{
    qof_session_end (fixture->session);
    fixture->session = NULL;

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
    do_test (qof_load_backend_library (GNC_LIB_REL_PATH, GNC_LIB_NAME),
             " loading gnc-backend-xml GModule failed");
    fprintf(stderr, "Blah\n");

    GNC_TEST_ADD (suitename, "Auto-clear all transactions", Fixture, NULL, setup, test_autoclear, teardown);
}
