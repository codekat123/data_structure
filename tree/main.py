import tkinter as tk
from tkinter import ttk, messagebox
import random

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None
        
    def insert(self, value):
        if not self.root:
            self.root = Node(value)
        else:
            self._insert_recursive(self.root, value)
    
    def _insert_recursive(self, node, value):
        if value < node.value:
            if node.left is None:
                node.left = Node(value)
            else:
                self._insert_recursive(node.left, value)
        else:
            if node.right is None:
                node.right = Node(value)
            else:
                self._insert_recursive(node.right, value)

class TreeVisualizer:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("Data Tree for Beginners")
        self.window.geometry("800x600")
        
        self.tree = BinaryTree()
        
        # Create interface
        self.create_widgets()
        
    def create_widgets(self):
        # Control frame
        control_frame = ttk.Frame(self.window)
        control_frame.pack(pady=10)
        
        # Value input field
        ttk.Label(control_frame, text="Enter value:").pack(side=tk.LEFT)
        self.value_entry = ttk.Entry(control_frame, width=10)
        self.value_entry.pack(side=tk.LEFT, padx=5)
        
        # Control buttons
        ttk.Button(control_frame, text="Add", command=self.add_value).pack(side=tk.LEFT, padx=5)
        ttk.Button(control_frame, text="Add Random Values", command=self.add_random_values).pack(side=tk.LEFT, padx=5)
        
        # Tree display area
        self.canvas = tk.Canvas(self.window, width=750, height=500, bg='white')
        self.canvas.pack(pady=10)
        
    def add_value(self):
        try:
            value = int(self.value_entry.get())
            self.tree.insert(value)
            self.draw_tree()
            self.value_entry.delete(0, tk.END)
        except ValueError:
            messagebox.showerror("Error", "Please enter a valid integer")
    
    def add_random_values(self):
        for _ in range(5):
            value = random.randint(1, 100)
            self.tree.insert(value)
        self.draw_tree()
    
    def draw_tree(self):
        self.canvas.delete("all")
        if self.tree.root:
            self._draw_node(self.tree.root, 375, 50, 200)
    
    def _draw_node(self, node, x, y, offset):
        # Draw circle and value
        self.canvas.create_oval(x-20, y-20, x+20, y+20, fill="lightblue")
        self.canvas.create_text(x, y, text=str(node.value))
        
        # Draw lines and child nodes
        if node.left:
            self.canvas.create_line(x, y+20, x-offset, y+80)
            self._draw_node(node.left, x-offset, y+80, offset/2)
        if node.right:
            self.canvas.create_line(x, y+20, x+offset, y+80)
            self._draw_node(node.right, x+offset, y+80, offset/2)
    
    def run(self):
        self.window.mainloop()

if __name__ == "__main__":
    app = TreeVisualizer()
    app.run() 