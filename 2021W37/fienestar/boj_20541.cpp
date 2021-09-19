/*
    앨범정리
    https://www.acmicpc.net/problem/20541
*/
#include <bits/stdc++.h>

using namespace std;

struct dir
{
	dir* parent;
	string name;
	size_t sdir_cnt;
	size_t sfile_cnt;
	map<string, dir*> sdir;
	set<string> sfile;
};

dir* root = new dir{
	nullptr,
	"album",
	0,
	0
};
dir* pnow;

void space(size_t n)
{
	while (n--)cout << " ";
}

void print_state(dir* i, size_t indent = 0)
{
	space(indent);
	if (i == pnow)
		cout << ">";

	cout << i->name << "(" << i->sdir_cnt << "," << i->sfile_cnt << ")\n";

	for (auto& sub : i->sfile) {
		space(indent + 4);
		cout << sub << "\n";
	}

	for (auto& sub : i->sdir) {
		print_state(sub.second, indent + 4);
	}
}

void prop(dir* i, size_t(dir::* attr), size_t value)
{
	do {
		i->*attr += value;
		i = i->parent;
	} while (i);
}

void run()
{
	string cmd, arg;
	cin >> cmd >> arg;
	//cout << cmd << " " << arg << "\n";

	dir& now = *pnow;

	if (cmd == "mkalb") {
		auto& sub = now.sdir[arg];
		if (sub == nullptr) {
			sub = new dir{
				pnow,
				arg,
				0,
				0
			};
			prop(pnow, &dir::sdir_cnt, 1);
		}
		else {
			cout << "duplicated album name\n";
		}

		return;
	}

	if (cmd == "rmalb") {
		auto obj = now.sdir.end();

		if (arg == "-1") {
			obj = now.sdir.begin();
		}
		else if (arg == "0") {
			cout << now.sdir_cnt << " " << now.sfile_cnt - now.sfile.size() << "\n";
			prop(pnow, &dir::sdir_cnt, -now.sdir_cnt);
			prop(pnow, &dir::sfile_cnt, now.sfile.size() - now.sfile_cnt);
			now.sdir.clear();
			return;
		}
		else if (arg == "1") {
			if (now.sdir.size())
				obj = prev(now.sdir.end());
		}
		else {
			obj = now.sdir.find(arg);
		}

		if (obj == now.sdir.end())
			cout << "0 0\n";
		else {
			auto& dir = *obj->second;
			cout << dir.sdir_cnt + 1 << " " << dir.sfile_cnt << "\n";
			prop(pnow, &dir::sdir_cnt, -dir.sdir_cnt - 1);
			prop(pnow, &dir::sfile_cnt, -dir.sfile_cnt);
			now.sdir.erase(obj);
		}
		return;
	}

	if (cmd == "insert") {
		auto it = now.sfile.find(arg);
		if (it == now.sfile.end()) {
			prop(pnow, &dir::sfile_cnt, 1);
			now.sfile.insert(arg);
		}
		else
			cout << "duplicated photo name\n";
		return;
	}

	if (cmd == "delete") {
		if (arg == "0") {
			cout << now.sfile.size() << "\n";
			prop(pnow, &dir::sfile_cnt, -now.sfile.size());
			now.sfile.clear();
			return;
		}

		auto it = now.sfile.end();
		if (arg == "-1")
			it = now.sfile.begin();
		else if (arg == "1") {
			if (now.sfile.size())
				it = prev(now.sfile.end());
		}
		else
			it = now.sfile.find(arg);

		if (it == now.sfile.end())
			cout << "0\n";
		else {
			cout << "1\n";

			prop(pnow, &dir::sfile_cnt, -1);
			now.sfile.erase(it);
		}
		return;
	}

	if (cmd == "ca") {
		if (arg == "..") {
			if (pnow->parent)
				pnow = now.parent;
		}
		else if (arg == "/")
			pnow = root;
		else if (auto it = now.sdir.find(arg); it != now.sdir.end()) {
			pnow = it->second;
		}

		cout << pnow->name << "\n";
		return;
	}
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	pnow = root;

	size_t N;
	cin >> N;

	while (N--) {
		run();
		//print_state(root);
	}
}