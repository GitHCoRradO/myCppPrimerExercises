#ifndef EX_13_34_36_37_H
#define EX_13_34_36_37_H

#include <string>
using std::string;
#include <set>
using std::set;

class Folder;

class Message {
friend class Folder;
friend void swap(Message &lhs, Message &rhs);
public:
	//default constructor
	explicit Message(const string &str = "") : contents(str) { }
	//copy control constructors
	Message(const Message &);
	Message &operator=(const Message &);
	~Message();
	//other operations
	void save(Folder &);
	void remove(Folder &);
private:
	string contents;
	set<Folder*> folders;
	//utility functions used by copy control members
	void add_to_Folders(const Message &);
	void remove_from_Folders();
};

void swap(Message&, Message&);

class Folder {
friend void swap(Folder&, Folder&);
friend class Message;
public:
	//default constructor
	Folder() = default;
	//copy control
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	//other operations
	void addMsg(Message *);
	void remMsg(Message *);
private:
	void add_Message(const Folder&);
	void remove_Message();
	set<Message*> messages;
};

void swap(Folder&, Folder&);

#endif
