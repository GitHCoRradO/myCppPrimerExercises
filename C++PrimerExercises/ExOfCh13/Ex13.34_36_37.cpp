#include "Ex13.34_36_37.h"
#include <iostream>

void Folder::addMsg(Message *m) {
	messages.insert(m);
}
void Folder::remMsg(Message *m) {
	messages.erase(m);
}
//Message class implementation
void Message::save(Folder &f) {
	folders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Folder &f) {
	folders.erase(&f);
	f.remMsg(this);
}
void Message::add_to_Folders(const Message &m) {
	for (auto f : m.folders)
		f->addMsg(this);
}
Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
	add_to_Folders(m);
}
void Message::remove_from_Folders() {
	for (auto f : folders)
		f->remMsg(this);
}
Message::~Message() {
	remove_from_Folders();
}
Message& Message::operator=(const Message &rhs) {
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}
void swap(Message &lhs, Message &rhs) {
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

//Folder class implementation
void Folder::add_Message(const Folder &f) {
	for (auto m : f.messages)
		(*m).folders.insert(this);
}
Folder::Folder(const Folder &f) : messages(f.messages) {
	add_Message(f);
}
void Folder::remove_Message() {
	for (auto m : messages)
		(*m).folders.erase(this);
}
Folder::~Folder() {
	remove_Message();
}
Folder& Folder::operator=(const Folder &rhs) {
	remove_Message();
	messages = rhs.messages;
	add_Message(rhs);
	return *this;
}
void swap(Folder &lhs, Folder &rhs) {
	using std::swap;
	lhs.remove_Message();
	rhs.remove_Message();
	swap(lhs.messages, rhs.messages);
	lhs.add_Message(lhs);
	rhs.add_Message(rhs);
}

int main() {
	return 0;
}
