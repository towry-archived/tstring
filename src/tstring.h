// Copyright (c) 2015, Towry Wang (http://towry.me)
// All rights reserved.
//
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#ifndef _TSTRING_SRC_TSTRING_H
#define _TSTRING_SRC_TSTRING_H

#include <iostream>
#include <memory.h>

namespace t {

class String {
public:
	String ();
	~String ();
	String (const char * ps);
	String (const String &that);
	String (String &&that);

	int Length () const;

	String& operator= (const String &that);
	String& operator= (String &&that);

	friend std::ostream& operator<< (std::ostream &_stream, String const &self);

private:
	char *hold_;
	int length_;
};

}

#endif
