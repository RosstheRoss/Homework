class Sequence<Base> {
	private Base[] bases;
	private int count;
	
	public int find (Base base){
		if (base == null) {
			for (int i=0; i<count; i+=1) {
				if (bases[i] == null) {
					return index;
				}
			}
		} else {
			for (int i=0; i<count; i+=1) {
				if (Base.equals(bases[i])) {
					return index;
				}
			}
		} 	return -1; 			//Fail case
	}
//While loop is basically an infinitely nexted series of if statements
	//(It's called loop unrolling)
//Sometimes the first execution is special (see below)
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append('[');
		if (count > 0) {
			builder.append(bases[0].toString())
			//Add a helper fo the null pointer
			for (int i = 1; i < count; i += 1) {
				builder.append(" ,");
				//Add a helper to not dereference the null pointer
				builder.append(bases[i].toString());
			}
		} builder.append(']')
		return builder.toString();
	}
//Arrays as sequences
	//Add		O(n) needed a copy loop
	//Delete	O(n) needed a copy loop - first element
	//Find		O(n) used linear search
		//Can we go faster? (Yes, probably)