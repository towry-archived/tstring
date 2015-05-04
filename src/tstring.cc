// Copyright (c) 2015, Towry Wang (http://towry.me)
// All rights reserved.
//
// Use of this source code is governed by a MIT license that can be
// found in the LICENSE file.

#include "tstring.h"

namespace t {

String::String () : hold_(nullptr), length_(0) {

}

String::~String () {
	delete hold_;
}

String::String (const char *ps) {
	int size;

	size = strlen(ps);
	hold_ = new char[size+1];
	memcpy(hold_, ps, size);
	hold_[size] = '\0';

	length_ = size;
}

String::String (const String &that) {
	int size;

	size = strlen(that.hold_);
	if (hold_ != nullptr) {
		delete hold_;
	}

	hold_ = new char[size + 1];
	memcpy(hold_, that.hold_, size);
	hold_[size] = '\0';

	length_ = size;
}

String::String (String &&that) {
	hold_ = that.hold_;
	length_ = that.length_;

	that.hold_ = nullptr;
}

int String::Length () const {
	return length_;
}

std::ostream& operator<< (std::ostream &_stream, String const &self) {
	_stream << self.hold_;
}

String& String::operator= (const String &that) {
	int size;

	if (&that == this) {
		return *this;
	}

	if (that.hold_ == nullptr) {
		return *this;
	}

	size = strlen(that.hold_);
	if (hold_ != nullptr) {
		delete hold_;
	}

	hold_ = new char[size + 1];
	memcpy(hold_, that.hold_, size);
	hold_[size] = '\0';

	length_ = size;

	return *this;
}

String& String::operator= (String &&that) {
	hold_ = that.hold_;
	length_ = that.length_;
	
	that.hold_ = nullptr;

#ifdef DEBUG
	std::cout <<"DEBUG: method '" << __func__ << "' called" << std::endl;
#endif

	return *this;
}

}
