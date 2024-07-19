-- core script class
local ChainSawScript = {}
local ChainSawScript_mt = { __index = ChainSawScript }

-- inits script base class
function ChainSawScript.Constructor(entity)
    local self = setmetatable({}, ChainSawScript_mt)
    self.Entity = entity
    return self
end

-- destroy entity with id
function ChainSawScript.Destroy(entity)
    ApiDestroy(entity)
end

-- inits script class
function Initializer()
    -- script class
    local ScripClass = {}
    local ScripClass_mt = { __index = ScripClass }
    setmetatable(ScripClass, { __index = ChainSawScript })

    -- constructor
    function ScripClass.Constructor(entity)
        local obj = ChainSawScript.Constructor(entity)
        self = setmetatable(obj, ScripClass_mt)
        return self
    end

    -- destroy self
    function ScripClass:Destroy()
        ApiDestroy(self.Entity)
    end

    -- get data
    function ScripClass:Get(type)
        if type == TRANSFORM then
            return ApiGetTransform(self.Entity)
        end
        print("invalid type:", type);
        return {}
    end

    -- export class
    return ScripClass
end

-- export module
return ChainSawScript
