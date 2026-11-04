/*
 * img4.h
 * Functions for handling the IMG4 format
 *
 * Copyright (c) 2013-2019 Nikias Bassen. All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef IDEVICERESTORE_IMG4_H
#define IDEVICERESTORE_IMG4_H

#ifdef __cplusplus
extern "C" {
#endif

int img4_stitch_component(const char* component_name, const void* component_data, size_t component_size, plist_t parameters, plist_t tss_response, void** img4_data, size_t *img4_size);
int img4_create_local_manifest(plist_t request, plist_t build_identity, plist_t* manifest);
/* The description of an IM4P (for iBoot stages its version, e.g. "iBoot-11881.140.96.700.4"), or NULL. */
char* img4_get_component_description(const void* data, size_t size);
/* Logs whether the ApImg4Ticket of the TSS response has an entry for the component and whether its
 * digest is the BuildManifest's and the IPSW image's, so a log shows which image iBoot could reject. */
void img4_log_ticket_entry(const char* component_name, const void* component_data, size_t component_size, plist_t tss_response, plist_t build_identity);

#ifdef __cplusplus
}
#endif

#endif
