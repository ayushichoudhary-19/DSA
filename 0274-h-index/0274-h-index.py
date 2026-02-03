class Solution:
    def hIndex(self, citations: List[int]) -> int:
        ans = 0
        for h in range(1,len(citations)+1):
            papersWithAtleastHCitations = 0
            for i in range(0,len(citations)):
                if(citations[i] >= h): 
                    papersWithAtleastHCitations += 1
            if(h <= papersWithAtleastHCitations):
                ans = max(ans,h)
        
        return ans