class BinarySearchTree {
    //BST의 constructor를 구현합니다.
    constructor(value) {
        this.x = value[0];
        this.y = value[1];
        this.value = value[2];
        this.left = null;
        this.right = null;
    }
    // tree에 value를 추가합니다.
    insert(value) {
      // 인자의 value가 this.value보다 작을 경우, 왼쪽 노드에서 진행합니다.
      if (value[0] < this.x) {
        // this.left에 아무것도 없을 경우, 새로운 자식 노드를 추가합니다.
        if (this.left === null) {
          this.left = new BinarySearchTree(value);
        }
        // this.left의 자식 노드가 있을 경우, 자식 노드에서 insert 재귀를 사용합니다.
        else {
          this.left.insert(value);
        }
      }
      // 인자의 value가 this.value보다 클 경우, 오른쪽 노드에서 진행합니다.
      else if (value[0] > this.x) {
        // this.right에 아무것도 없을 경우, 새로운 자식 노드를 추가합니다.
        if (this.right === null) {
          this.right = new BinarySearchTree(value);
        }
        // this.left의 자식 노드가 있을 경우, 자식 노드에서 insert 재귀를 사용합니다.
        else {
          this.right.insert(value);
        }
      }
    }
   
    //tree를 전위 순회 합니다.
    preorder(callback) {
      callback(this.value);
      if (this.left) {
        this.left.preorder(callback);
      }
      if (this.right) {
        this.right.preorder(callback);
      }
    }
    //tree를 후위 순회 합니다
    postorder(callback) {
      if (this.left) {
        this.left.postorder(callback);
      }
      if (this.right) {
        this.right.postorder(callback);
      }
      callback(this.value);
    }
  }

function solution(nodeinfo) {
    let answer = [[],[]];

    nodeinfo.forEach((info, idx)=>{
        info.push(idx+1)
    })
    
    nodeinfo.sort((a,b) => {
        if(a[1] !== b[1]) return b[1]- a[1];
        return a[0] - b[0];
    })
  
    let tree = new BinarySearchTree(nodeinfo[0])
    for(let i=1; i<nodeinfo.length; i++) tree.insert(nodeinfo[i])
    
    tree.preorder((v)=>answer[0].push(v))
    tree.postorder((v)=>answer[1].push(v))
    return answer;
}
