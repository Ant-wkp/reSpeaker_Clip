/*
 * Copyright (c) 2025 Seeed Technology Co., Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CLIP_ICONS_H
#define CLIP_ICONS_H

#include <stdint.h>

/**
 * @file icons.h
 * @brief Icon library for CLIP display
 *
 * Icons are stored as const bitmap data in Flash (ROM), not RAM.
 * Format: column-major order, 1 bit per pixel, most significant bit first.
 * Each column uses (height + 7) / 8 bytes.
 */

#define ICON_WIDTH  24
#define ICON_HEIGHT 24
#define ICON_SIZE_BYTES 72  /* 24 columns * 3 bytes per column */

/**
 * @brief Icon identifiers
 */
typedef enum {
	ICON_NONE = 0,
	ICON_WIFI_CONNECTED,     /**< WiFi connected icon */
	ICON_WIFI_TRANSFER,      /**< WiFi transfer icon */
	ICON_BLE_CONNECTED,      /**< BLE connected icon */
	ICON_BLE_TRANSFER,       /**< BLE transfer icon */
	ICON_BATTERY_FULL,       /**< Battery full icon */
	ICON_BATTERY_CHARGING,   /**< Battery charging icon */
	ICON_BATTERY_LOW,        /**< Battery low icon */
	ICON_USB_CONNECTED,      /**< USB connected icon */
	ICON_MIC_NORMAL,         /**< Normal microphone icon */
	ICON_MIC_ENHANCED,       /**< Enhanced microphone icon */
	ICON_MIC_MUTED,          /**< Muted microphone icon */
	ICON_CONNECTED,          /**< Generic connected icon */
	ICON_DISCONNECTED,       /**< Generic disconnected icon */
	ICON_PHONE,              /**< Phone icon */
	ICON_WIRED_CHARGING,     /**< Wired charging icon (power plug) */
	ICON_ARROW,              /**< Arrow icon */
	ICON_WIFI_CLIENT,        /**< WiFi client connected icon */
	ICON_WIFI_UDP,           /**< WiFi UDP transfer icon */
	ICON_WIRED_TRANSFER,     /**< Wired transfer icon */
	ICON_LOW_BATTERY_DISPLAY, /**< Low battery display icon */
	ICON_DISCONNECT_NOT_TRANSFORM, /**< Disconnect not transfer icon */
	ICON_OTA,                 /**< OTA upgrade icon */
	ICON_POWER,               /**< Power button icon */
	ICON_DINO,                /**< Chromium T-Rex standing icon */
} icon_id_t;

/**
 * @brief Get icon bitmap data by ID
 *
 * @param id Icon identifier
 * @param width Output: icon width in pixels
 * @param height Output: icon height in pixels
 * @return Pointer to icon bitmap data, or NULL if not found
 */
const uint8_t* icon_get_bitmap(icon_id_t id, uint8_t *width, uint8_t *height);

/**
 * @brief Draw bitmap icon to buffer
 *
 * @param buf Frame buffer
 * @param x X position
 * @param y Y position
 * @param bitmap Icon bitmap data in column-major format
 * @param width Icon width in pixels
 * @param height Icon height in pixels
 */
void icon_draw_bitmap(uint8_t *buf, int x, int y,
                      const uint8_t *bitmap, uint8_t width, uint8_t height);

#endif /* CLIP_ICONS_H */
