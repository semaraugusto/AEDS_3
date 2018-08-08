#include <stdio.h>

void print_array(int *vectorAux, int *data, int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("%d %d\n", data[i], vectorAux[i]);
	}
	printf("\n");
}

int partition(int *vectorAux, int *data, int left, int right, int piv) {
	int pval = data[piv];

	// swap the pivot value with the right
	int tmp = data[piv];
	data[piv] = data[right];
	data[right] = tmp;

	tmp = vectorAux[piv];
	vectorAux[piv] = vectorAux[right];
	vectorAux[right] = tmp;

	// scan from left to right
	int i;
	int s = left; // save left to stored index
	for(i = left; i < right; i++) {

		// if val is less than pivot value,
		if(data[i] < pval) {

			// swap val with stored index
			tmp = data[s];
			data[s] = data[i];
			data[i] = tmp;

			tmp = vectorAux[s];
			vectorAux[s] = vectorAux[i];
			vectorAux[i] = tmp;
			s++; // shift the stored index right
		}
	}

	/* swap the stored index with the right most
	 * (bring the pivot back)
	 */
	tmp = data[s];
	data[s] = data[right];
	data[right] = tmp;

	tmp = vectorAux[s];
	vectorAux[s] = vectorAux[right];
	vectorAux[right] = tmp;

	return s;
}

void quicksort(int *vectorAux, int *data, int left, int right) {
	if(left < right) {

		// pivot around the middle
		int pivot = data[(right + left)/2];
		int newpivot = partition(data, left, right, pivot);

		// sort the left and right sides
		quicksort(vectorAux, data, left, newpivot-1);
		quicksort(vectorAux, data, newpivot+1, right);
	}
}
