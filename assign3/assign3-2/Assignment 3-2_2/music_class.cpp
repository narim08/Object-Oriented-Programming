#include "music_class.h"

myMusic::myMusic():m_title{NULL}, m_singer{NULL}, m_album{NULL}, m_track_no(0), m_year(0){}
myMusic::~myMusic() {
	if (m_title != nullptr) {
		delete[] m_title;
	}
	if (m_singer != nullptr) {
		delete[] m_singer;
	}
	if (m_album != nullptr) {
		delete[] m_album;
	}
}

void myMusic::setTitle(char* title) {
	if (m_title != nullptr) { //이미 존재하는 경우 먼저 삭제
		delete[] m_title;
	}
	m_title = new char[strlen(title) + 1]; //깊은복사 위해 동적할당
	strcpy(m_title, title);
}

void myMusic::setSinger(char* singer) {
	if (m_singer != nullptr) {
		delete[] m_singer;
	}
	m_singer = new char[strlen(singer) + 1];
	strcpy(m_singer, singer);
}

void myMusic::setAlbum(char* album) {
	if (m_album != nullptr) {
		delete[] m_album;
	}
	m_album = new char[strlen(album) + 1];
	strcpy(m_album, album);
}

void myMusic::setYear(int year) {
	m_year = year;
}

void myMusic::setTrackNo(int track_no) {
	m_track_no = track_no;
}


char* myMusic::getTitle() {
	return m_title;
}

char* myMusic::getSinger() {
	return m_singer;
}

char* myMusic::getAlbum() {
	return m_album;
}

int myMusic::getYear() {
	return m_year;
}

int myMusic::getTrackNo() {
	return m_track_no;
}