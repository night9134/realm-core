#ifndef __TDB_INDEX__
#define __TDB_INDEX__

#include "Column.h"

class Index : public Column {
public:
	Index();
	Index(ColumnDef type, Array* parent=NULL, size_t pndx=0);
	Index(void* ref);
	Index(void* ref, Array* parent, size_t pndx);

	void BuildIndex(const Column& c);

	bool Insert64(size_t ndx, int64_t value);

	size_t Find(int64_t value);

protected:
	// B-Tree functions
	NodeChange DoInsert(size_t ndx, int64_t value);

	// Node functions
	bool NodeAdd(void* ref);

	bool LeafInsert(size_t ref, int64_t value);

	int64_t MaxValue() const;
};

#endif //__TDB_INDEX__
