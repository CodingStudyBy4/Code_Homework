def solution(begin, target, words):
    if target not in set(words):
        return 0
    queue = [begin]
    total_count = 0
    while words:
        for value in queue:
            # 바꾸게 될 단어를 저장하는 변수
            temp = []
            for word in words:
                count = 0
                for i in range(len(word)):
                    # 원래 단어와 words의 각 단어를 비교해서 글자가 다르면 count 증가.
                    if value[i] != word[i]:
                        count += 1
                        if count == 2:
                            break
                # 바꿀 수 있는 단어면 temp에 저장하고 words에서 단어를 삭제한다.
                if count == 1:
                    temp.append(word)
                    words.remove(word)
        total_count += 1
        if target == "".join(temp):
            return total_count
        else:
            queue = temp
    return 0
print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))
print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"]))