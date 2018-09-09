public class ListElement<T> {

	public ListElement(T val) {
		this.val = val;
	}

	public ListElement(T val, ListElement<T> next) {
		this.val = val;
		this.next = next;
	}
	
	ListElement<T> deleteList(ListElement<T> head) {
		return null;
	}
	
	ListElement<T> deleteElement(ListElement<T> head, T data) {
		
		if (head == null) {
			throw new IllegalArgumentException("Attempt to delete element from empty list.");
		}
		
		if (head.val == data) {
			head = head.next;
			return head;
		}
		
		while (head != null) {
			if (head.next.val == data) {
				head.next = head.next.next;
				break;
			}
			
			head = head.next;
		}
		
		return head;
	}
	
	ListElement<T> deleteElement(ListElement<T> head, ListElement<T> n) {
		if (head == null || n == null) {
			throw new IllegalArgumentException("Attempt to delete element from empty list.");
		}
		
		if (head == n) {
			head = head.next;
		}
		else {
			while (head != null) {
				if (head.next == n)
				{
					head.next = head.next.next;
					break;
				}
				
				head = head.next;
			}
		}

		return head;
	}
	
	ListElement<T> insertInFront(ListElement<T> head, T data) {
		head = new ListElement<T>(data, head);
		return head;
	}
	
	ListElement<T> find(ListElement<T> head, T data) {
		while (head != null) {
			if (head.val == data) {
				return head;
			}
			
			head = head.next;
		}
		
		return null;
	}
	
	ListElement<T> removeHead(ListElement<T> head) {
		
		if (head == null) {
			throw new IllegalArgumentException("Attempt to delete head from empty list.");
		}
		
		return head.next;
	}
	
	ListElement<T> append(ListElement<T> head, T data) {
		if (head == null) {
			head = new ListElement<T>(data);
		}
		else {
			while (head != null) {
				if (head.next == null) {
					head.next = new ListElement<T>(data);
				}
				
				head = head.next;
			}
		}
		return head;
	}
	
	ListElement<T> insertAfter(ListElement<T> head, ListElement<T> n, T data)
	{
		if (n == null) {
			throw new IllegalArgumentException("Attempt to insert after null element.");
		}

		if (head == null) {
			return new ListElement<T>(data);
		}
				
		while (head != null) {
			if (head == n) {
				n.next = head.next;
				head.next = n;
				break;
			}
			
			head = head.next;
		}
		
		return head;
	}
	
	ListElement<T> insertBefore(ListElement<T> head, ListElement<T> n, T data) {
		if (n == null) {
			throw new IllegalArgumentException("Attempt to insert before null element.");
		}
		
		if (head == null) {
			return new ListElement<T>(data);
		}
		
		while (head != null) {
			if (head.next == n) {
				ListElement<T> tmp = new ListElement<T>(data, n);
				head.next = tmp;
				break;
			}
			
			head = head.next;
		}
		
		return head;
	}
	
	public T val;
	public ListElement<T> next;
}
