scary_virus = True
need_internet = True
live_on_campus = True
go_to_HKUST = (live_on_campus or need_internet) \
	and not scary_virus
print(go_to_HKUST)
