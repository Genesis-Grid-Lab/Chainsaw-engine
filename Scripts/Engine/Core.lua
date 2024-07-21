-- core script class
local ChainSawScript = {}
local ChainSawScript_mt = { __index = ChainSawScript }

-- inits script base clasee
function ChainSawScript.Constructor(entity)
    local self = setmetatable({}, ChainSawScript_mt)
    self.Entity = entity
    return self
end

-- destroy entity with id
function ChainSawScript.Destroy(entity)
    print("destroylua")
    ApiDestroy(entity)
end

-- inits script class
function Initializer()
    -- script class
    local ScriptKlass = {}
    local ScriptKlass_mt = { __index = ScriptKlass }
    setmetatable(ScriptKlass, { __index = ChainSawScript })

    -- constructor
    function ScriptKlass.Constructor(entity)
        local obj = ChainSawScript.Constructor(entity)
        self = setmetatable(obj, ScriptKlass_mt)
        return self
    end

    -- apply force to rigidbody
    function ScriptKlass:ApplyForce(force)
        ApiApplyForce(self.Entity, force)
    end

    -- destroy self
    function ScriptKlass:Destroy()
        print("DESTROYCLASS")
        ApiDestroy(self.Entity)
    end

    -- get data
    function ScriptKlass:Get(type)
        if type == TRANSFORM then
            return ApiGetTransform(self.Entity)
        end
        print("invalid type:", type);
        return {}
    end

    -- export class
    return ScriptKlass
end

-- export module
return ChainSawScript
