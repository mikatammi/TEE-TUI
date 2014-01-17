/*****************************************************************************
** Copyright (C) 2014 Intel Corporation.                                    **
**                                                                          **
** Licensed under the Apache License, Version 2.0 (the "License");          **
** you may not use this file except in compliance with the License.         **
** You may obtain a copy of the License at                                  **
**                                                                          **
**      http://www.apache.org/licenses/LICENSE-2.0                          **
**                                                                          **
** Unless required by applicable law or agreed to in writing, software      **
** distributed under the License is distributed on an "AS IS" BASIS,        **
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. **
** See the License for the specific language governing permissions and      **
** limitations under the License.                                           **
*****************************************************************************/

#ifndef __TEE_TUI_DATA_TYPES_H__
#define __TEE_TUI_DATA_TYPES_H__

#include <stdint.h>
#include <stddef.h>

enum TEE_TUIEntryFieldMode {
	TEE_TUI_HIDDEN_MODE = 0,
	TEE_TUI_CLEAR_MODE,
	TEE_TUI_TEMPORARY_CLEAR_MODE
};

enum TEE_TUIEntryFieldType {
	TEE_TUI_NUMERICAL = 0,
	TEE_TUI_ALPHANUMERICAL
};

enum TEE_TUIScreenOrientation {
	TEE_TUI_PORTRAIT = 0,
	TEE_TUI_LANDSCAPE
};

enum TEE_TUIButtonType {
	TEE_TUI_CORRECTION = 0,
	TEE_TUI_OK,
	TEE_TUI_CANCEL,
	TEE_TUI_VALIDATE,
	TEE_TUI_PREVIOUS,
	TEE_TUI_NEXT,
        TEE_TUI_NUMBER_BUTTON_TYPES
};

enum TEE_TUIImageSource {
	TEE_TUI_NO_SOURCE = 0,
	TEE_TUI_REF_SOURCE,
	TEE_TUI_OBJECT_SOURCE
};

struct TEE_TUIImage {
	TEE_TUIImageSource source;
	union {
		struct {
			void *image;
			size_t imageLength;
		} ref;

		struct {
			uint32_t storageID;
			void *objectID;
			size_t objectIDLen;
		} object;
	};

	uint32_t width;
	uint32_t height;
};

struct TEE_TUIScreenLabel {
	char *text;
	uint32_t textXOffset;
	uint32_t textYOffset;
	uint8_t textColor[3];
	TEE_TUIImage image;
	uint32_t imageXOffset;
	uint32_t imageYOffset;
};

struct TEE_TUIButton {
	char *text;
	TEE_TUIImage image;
};

struct TEE_TUIScreenConfiguration {
	TEE_TUIScreenOrientation screenOrientation;
	TEE_TUIScreenLabel label;
	TEE_TUIButton * buttons[TEE_TUI_NUMBER_BUTTON_TYPES];
	bool requestedButtons[TEE_TUI_NUMBER_BUTTON_TYPES];
};

struct TEE_TUIScreenButtonInfo {
	char *buttonText;
	uint32_t buttonWidth;
	uint32_t buttonHeight;
	bool buttonTextCustom;
	bool buttonImageCustom;
};

struct TEE_TUIScreenInfo {
	uint32_t grayscaleBitsDepth;
	uint32_t redBitsDepth;
	uint32_t greenBitsDepth;
	uint32_t blueBitsDepth;
	uint32_t widthInch;
	uint32_t heightInch;
	uint32_t maxEntryFields;
	uint32_t entryFieldLabelWidth;
	uint32_t entryFieldLabelHeight;
	uint32_t maxEntryFieldLength;
	uint8_t labelColor[3];
	uint32_t labelWidth;
	uint32_t labelHeight;

	TEE_TUIScreenButtonInfo buttonInfo[TEE_TUI_NUMBER_BUTTON_TYPES];
};

struct TEE_TUIEntryField {
	char *label;
	TEE_TUIEntryFieldMode mode;
	TEE_TUIEntryFieldType type;
	uint32_t minExpectedLength;
	uint32_t maxExpectedLength;
	char *buffer;
	size_t bufferLength;
};

#endif /* __TEE_TUI_DATA_TYPES_H__ */

